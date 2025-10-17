#pragma once

#include <TObject.h>
#include <map>
#include <vector>

#include "TOverrideStreamer.hh"

class TObjInSTL : public TObject {
private:
  std::vector<TOverrideStreamer> m_objVec;
  std::map<int, TOverrideStreamer> m_objMap;

public:
  TObjInSTL(int val = 0) : TObject() {
    // Fill the STL containers with some data
    for (int i = 0; i < 5; ++i) {
      m_objVec.emplace_back(val + i);
      m_objMap.emplace(i, TOverrideStreamer(val + i * 10));
    }
  }

  ClassDef(TObjInSTL, 1);
};
