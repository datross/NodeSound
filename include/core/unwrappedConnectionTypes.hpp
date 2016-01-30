/* unwrappedConnectionTypes.hpp */

#ifndef U_CONNECTION_TYPES
#define U_CONNECTION_TYPES

#include <cstdint>
#include <vector>

namespace nsd {

/* midi event, it can hold several midi real events */
typedef std::vector<uint8_t*> midiEvent;

/* audio sample */
typedef float audioSample;

/* audio buffer */
typedef float* audioBuffer;

}

#endif
