// - ------------------------------------------------------------------------------------------ - //
#ifdef USES_SDLLOG
// - ------------------------------------------------------------------------------------------ - //
// Use SDL Logging //
// - ------------------------------------------------------------------------------------------ - //
#include <API/API_SDL2.h>
// - ------------------------------------------------------------------------------------------ - //
#define FLOG_FUNCV( ... )		SDL_LogMessageV( SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, __VA_ARGS__ )
#define FLOG_FUNC( ... )		SDL_LogMessage( SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, __VA_ARGS__ )
// - ------------------------------------------------------------------------------------------ - //
#define _FLogFlush() ;
#define _FLogColor( ... ) ;
// - ------------------------------------------------------------------------------------------ - //
void FLogInit( const char* ) {
}
// - ------------------------------------------------------------------------------------------ - //
void FLogExit() {	
}
// - ------------------------------------------------------------------------------------------ - //
#endif // USES_SDLLOG //
// - ------------------------------------------------------------------------------------------ - //
