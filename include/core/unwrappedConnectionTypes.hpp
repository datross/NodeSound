/* unwrappedConnectionTypes.hpp */

#ifndef U_CONNECTION_TYPES
#define U_CONNECTION_TYPES

#include <cstdlib>
#include <vector>

namespace nsd {

/* midi event, it can hold several midi real events */
typedef std::vector<char*> midiEvent;

/* audio sample */
typedef float audioSample;

/* audio buffer */
typedef float* audioBuffer;

}

#endif
