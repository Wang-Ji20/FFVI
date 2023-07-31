//===------------------------------------------===
// ffvi 2023
//
// Identification: include\main\game_stream.hh
//
// Author: Ji Wang <jiwangcdi@gmail.com>
//
//===------------------------------------------===

#pragma once

#include "main/event.hh"
#include "main/listener.hh"
#include "main/publisher.hh"

#include <unordered_map>
#include <unordered_set>
#include <memory>

/// game stream builds up the global message broker for this game.
/// components of the game can communicate with each other through game stream
/// they can subscribe certain `events` from game stream or publish them.
/// pub/sub must through composition of listener & publisher, rather than
/// inheritance.

namespace ffvi {

class GameStream {
  using TopicId = int;
public:
  GameStream();
  ~GameStream();

  enum SpecialTopicId {
    kInvalidTopicId = -1,
    kAllTopicId = -2,
  };

  /// we give away the ownership of listener & publisher to the object
  /// because the Game Stream is always there. It does not destory something.
  ///
  /// It's the responsibility of the object to destory the listener & publisher
  auto Subscribe(TopicId topic, EventCallback callback) -> std::unique_ptr<Listener>;
  auto Unregister(Listener &listener) -> void;

  /// actually we don't care about whether there is a publisher or not
  auto Publish(TopicId topic, bool fanOut = false) -> std::unique_ptr<Publisher>;

  void Notify(Event &event);
private:
  std::unordered_map<TopicId, std::unordered_set<Listener &>> listeners_;
};

} // namespace ffvi
