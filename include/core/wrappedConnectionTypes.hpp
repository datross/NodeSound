/* wrappedConnectionTypes.hpp */

#ifndef W_CONNECTION_TYPES
#define W_CONNECTION_TYPES

#include <vector>
#include "core/unwrappedConnectionTypes.hpp"

namespace nsd {

/* class encapsulating an audio region */

class AudioRegion 
{
public:
    AudioRegion(unsigned int bufferLength, unsigned int sampleRate);
    
    /* these accessors do not check validity of 'buffer' */
    audioBuffer getBuffer(unsigned int buffer);
    audioBuffer getBuffer(float time);
    
    std::vector<audioBuffer> * getBuffers();
    
    float getDuration();
    unsigned int getBufferLength();
    
private:
    /* audioBuffers, of length 'bufferLength', the audio migth not fill the entire last buffer which is completed with 0 */
    std::vector<audioBuffer> buffers;
    
    unsigned int bufferLength;
    
    /* how many 'audioSample' are in a second */
    unsigned int sampleRate;
};

/* stores a midi event with his time */

typedef struct midiEventSync {
    midiEvent event;
    
    /* relative to the midi region */
    float time;
} midiEventSync;

/* class encapsulating a midi region */
/* TODO : implement a better performance data structure than vector */
class MidiRegion
{
public:
    MidiRegion();
    
    int addEvent(midiEventSync&);
    int removeEvent(const midiEventSync&);
    
    /* returns NULL if no event corresponding is found */
    midiEventSync * getEvent(float time);
private:
    /* each element is an array of simultaneous events, and simultaneous events must be in the same element */
    std::vector<midiEventSync*> events;
    
    float duration;
};


}

#endif
