#include <TFile.h>
#include <TTree.h>

#include "TObjInSTL.hh"
#include "TOverrideStreamer.hh"

int main() {
  TFile f("demo-data.root", "RECREATE");
  TTree t("my_tree", "tree");

  TOverrideStreamer override_streamer;
  t.Branch("override_streamer", &override_streamer);

  TObjInSTL obj_in_stl;
  t.Branch("obj_in_stl", &obj_in_stl);

  for (int i = 0; i < 10; i++) {
    override_streamer = TOverrideStreamer(i);
    obj_in_stl = TObjInSTL(i);
    t.Fill();
  }

  t.Write();
  f.Close();
}
