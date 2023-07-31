//===------------------------------------------===
// ffvi 2023
//
// Identification: include\main\listener.hh
//
// Author: Ji Wang <jiwangcdi@gmail.com>
//
//===------------------------------------------===

#pragma once

#include "main/event.hh"
#include <functional>

namespace ffvi {

using EventCallback = std::function<void(Event &)>;

class Listener {
  friend class GameStream;

public:
  ~Listener();

private:
  Listener(GameStream &game_stream, int topic, const EventCallback &callback)
      : topic_(topic), callback_(callback), gameStream_(game_stream){};
  int topic_;
  const EventCallback &callback_;
  GameStream &gameStream_;
};

} // namespace ffvi
