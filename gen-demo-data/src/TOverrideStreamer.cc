#include "TOverrideStreamer.hh"
#include <TObject.h>

#include <iostream>

ClassImp( TOverrideStreamer );

void TOverrideStreamer::Streamer( TBuffer& b ) {
    if ( b.IsWriting() )
    {
        TObject::Streamer( b ); // Call base class Streamer
        b << m_int;
        b << 0x12345678; // Write a tag
        b << m_double;
    }
    else
    {
        TObject::Streamer( b ); // Call base class Streamer

        b >> m_int;

        // Read the tag
        unsigned int tag;
        b >> tag;
        if ( tag != 0x12345678 )
        {
            std::cerr << "Error: Unexpected tag value: " << std::hex << tag << std::dec
                      << std::endl;
            return;
        }

        b >> m_double;
    }
}
