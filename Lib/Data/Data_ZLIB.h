// - ------------------------------------------------------------------------------------------ - //
// DataCompression - Compression code for Data library //
// - ------------------------------------------------------------------------------------------ - //
#ifndef __Library_Data_Data_ZLIB_H__
#define __Library_Data_Data_ZLIB_H__
// - ------------------------------------------------------------------------------------------ - //
// TODO: Add endianness adaptation to this code.  If we're in big endian mode, be sure we //
//   convert sizes defaulty encoded as little endian to big endian. //
// - ------------------------------------------------------------------------------------------ - //
#include "Data_Core.h"
#include "DataBlock_Core.h"
#include "DataBlock_ZLIB.h"
// - ------------------------------------------------------------------------------------------ - //
//namespace Data {
// - ------------------------------------------------------------------------------------------ - //
// Decode packed ZLIB data to a new DataBlock //
inline const st32 unpack_ZLIB_Data( void* _Src, const st32 _SrcSize, void** _Dest, st32* _DestSize ) {
	// Assume the compressed DataBlock contains a DataBlock, who's size is the uncompressed size //
	DataBlock* Compressed = reinterpret_cast<DataBlock*>(_Src);
	
	st32 UncompressedSize = Compressed->Size;

	// Allocate a memory block equal to the uncompressed size //
	char* Uncompressed = (char*)new_Data( UncompressedSize );
	
	// Decompress the Data //
	int Error = uncompress(
		(Bytef*)Uncompressed,
		(uLongf*)&UncompressedSize,
		(const Bytef*)Compressed->Data, // Compressed Data (After Size, and Uncompressed Size (8 bytes)) //
		_SrcSize - 4 // Source size, since we have an extra 4 byte uncompressed size //
		);
	// TODO: Assert on uncompress error //
	//if ( Error != Z_OK )
	
	*_Dest = Uncompressed;
	*_DestSize = UncompressedSize;
	
	// Return the uncompressed buffer //
	return UncompressedSize;
}
//// - ------------------------------------------------------------------------------------------ - //
//// Encode packed ZLIB data to a new DataBlock //
//inline DataBlock* pack_ZLIB_Data( void* _Src ) {
//	// Allocate worst case space to store compressed data //
//	DataBlock* Compressed = new_DataBlock( _Src->Size + (_Src->Size / 1000) + 12 + 4 );
//	
//	st32* UncompressedSize = reinterpret_cast<st32*>(&Compressed->Data[0]);
//	*UncompressedSize = 0;
//	st32 CompressedSize = Compressed->Size-4;
//	
//	// Compress the Data //
//	int Error = compress(
//		(Bytef*)(&(Compressed->Data[4])),
//		(uLongf*)&CompressedSize,
//		(const Bytef*)_Src->Data,
//		_Src->Size
//		//Z_DEFAULT_COMPRESSION // Compression level.  1 best - 9 worst. 0 none. default is 6 //
//		);
//	// TODO: Assert on compress error //
//	//if ( Error != Z_OK )
//	
//	// Store Sizes //
//	Compressed->Size = CompressedSize + 4;
//	*UncompressedSize = _Src->Size;
//
//	// If zlib worked, zlib will have changed the size in the DataBlock to less than the //
//	//   memory allocated.  Thusly, we can call reallocate to force the data buffer to be //
//	//   re-allocated to reduce memory usage (causing normal OS fragmentation). //
//	reallocate_DataBlock( &Compressed );
//	
//	// Return the compressed buffer //
//	return Compressed;
//}
//// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
//}; // namespace Data //
// - ------------------------------------------------------------------------------------------ - //
#endif // __Library_Data_Data_ZLIB_H__ //
// - ------------------------------------------------------------------------------------------ - //
