#include <TObject.h>

#include "TOverrideStreamer.hh"

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
        if ( tag != 0x12345678 ) { throw std::runtime_error( "Unexpected tag value." ); }

        b >> m_double;
    }
}
