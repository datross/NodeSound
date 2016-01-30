/* wrappedConnectionTypes.cpp */

#include "core/wrappedConnectionTypes.hpp"

using namespace nsd, std;

/* ----- AudioRegion ----- */

AudioRegion::AudioRegion(uint32_t bufferLength, uint32_t sampleRate) 
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
    
}

midiEventSync * MidiRegion::getEvent(float time) {
    /* binary search in the vector */
    vector<midiEventSync*>::iterator begin = events.begin(), end = events.end(), mid;
    
    while(begin <= end) {
        mid = (end + begin) / 2;
        if((*mid)->time == time) {
            return *mid;
        if((*mid)->time > time) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    
    return NULL;
}
