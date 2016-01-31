/* wrappedConnectionTypes.cpp */

#include "core/wrappedConnectionTypes.hpp"

using namespace std;
using namespace nsd;

/* ----- AudioRegion ----- */

AudioRegion::AudioRegion(unsigned int bufferLength, unsigned int sampleRate) 
    : bufferLength(bufferLength), sampleRate(sampleRate)
{
}

audioBuffer AudioRegion::getBuffer(unsigned int buffer) {
    return buffers[buffer];
}

audioBuffer AudioRegion::getBuffer(float time) {
    return buffers[(unsigned int)(time * sampleRate) / bufferLength];
}

float AudioRegion::getDuration() {
    return (float)(buffers.size() * bufferLength) / (float)sampleRate;
}

unsigned int AudioRegion::getBufferLength() {
    return bufferLength;
}

std::vector<audioBuffer> * AudioRegion::getBuffers() {
    return &buffers;
}

/* ----- MidiRegion ----- */

MidiRegion::MidiRegion() {
}

int MidiRegion::addEvent(midiEventSync& eventSync) {
    /* check if there is an event at the same time */
    return 0;
}

int removeEvent(const midiEventSync&) {
    return 0;
}
    

midiEventSync * MidiRegion::getEvent(float time) {
    /* binary search in the vector */
    unsigned int begin = 0, end = events.size(), mid;
    
    while(begin <= end) {
        mid = (end + begin) / 2;
        if(events[mid]->time == time)
            return events[mid];
        if(events[mid]->time > time) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return NULL;
}
