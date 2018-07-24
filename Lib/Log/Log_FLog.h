// - ------------------------------------------------------------------------------------------ - //
#ifndef __GEL_DEBUG_LOG_FLOG_H__
#define __GEL_DEBUG_LOG_FLOG_H__
// - ------------------------------------------------------------------------------------------ - //
#include <stdarg.h>
// - ------------------------------------------------------------------------------------------ - //
#ifndef NO_FLOGGING
// - ------------------------------------------------------------------------------------------ - //
#ifndef USES_FLOG_COLORS
	void FLogColor( const int InColor );
#else // USES_FLOG_COLORS //
	#define FLogColor( ... ) ;
#endif // USES_FLOG_COLORS //
// - ------------------------------------------------------------------------------------------ - //
void FLogInit( const char* );
void FLogExit();
void FLogFlush();

void FLogAlways( const char* s, va_list vargs );
void _FLogAlways( const char* s, va_list vargs );
// - ------------------------------------------------------------------------------------------ - //
#else // NO_FLOGGING //
// - ------------------------------------------------------------------------------------------ - //
#define FLogColor( ... ) ;

#define FLogInit( ... ) ;
#define FLogExit() ;

#define FLogFlush( ... ) ;

#define FLogAlways( ... ) ;
#define _FLogAlways( ... ) ;
// - ------------------------------------------------------------------------------------------ - //
#endif // NO_FLOGGING //
// - ------------------------------------------------------------------------------------------ - //
#endif // __GEL_DEBUG_LOG_FLOG_H__ //
// - ------------------------------------------------------------------------------------------ - //