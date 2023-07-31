//===------------------------------------------===
// ffvi 2023
//
// Identification: lib\main\listener.cc
//
// Author: Ji Wang <jiwangcdi@gmail.com>
//
//===------------------------------------------===

#include "main/listener.hh"
#include "main/game_stream.hh"

namespace ffvi {

Listener::~Listener() {
  gameStream_.Unregister(*this);
}

} // namespace ffvi
