#include <TFile.h>
#include <TTree.h>

#include "TOverrideStreamer.hh"

int main() {
    TFile f( "demo-data.root", "RECREATE" );
    TTree t( "my_tree", "tree" );

    TOverrideStreamer override_streamer;
    t.Branch( "standalone_obj", &override_streamer );

    TObjToSave obj_in_stl;
    t.Branch( "my_obj", &obj_in_stl );

    for ( int i = 0; i < 10; i++ )
    {
        override_streamer = TOverrideStreamer( i );
        obj_in_stl        = TObjToSave( i );
        t.Fill();
    }

    t.Write();
    f.Close();
}
