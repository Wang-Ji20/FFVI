//===------------------------------------------===
// ffvi 2023
//
// Identification: include\main\event.hh
//
// Author: Ji Wang <jiwangcdi@gmail.com>
//
//===------------------------------------------===

#pragma once

namespace ffvi {

class GameStream;

class Event {
  friend class GameStream;
public:
  Event();
private:
  int topic_;
  int id_;
  GameStream &game_stream_;
};

} // namespace ffvi
