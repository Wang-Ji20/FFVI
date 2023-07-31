//===------------------------------------------===
// ffvi 2023
//
// Identification: include\main\publisher.hh
//
// Author: Ji Wang <jiwangcdi@gmail.com>
//
//===------------------------------------------===

#pragma once

namespace ffvi {

class Publisher {
  friend class GameStream;

private:
  Publisher(GameStream &game_stream, int topic, bool fanOut)
      : topic_(topic), fanOut_(fanOut), gameStream_(game_stream){};
  int topic_;
  bool fanOut_;
  GameStream &gameStream_;
};

} // namespace ffvi
