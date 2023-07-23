//===------------------------------------------===
// FFVI 2023
//
// Identification: tool\tty_client\main.cc
//
// Author: Ji Wang <jiwangcdi@gmail.com>
//
//===------------------------------------------===

#include "main/ffvi.hh"
#include "common/logger.hh"

auto main(int argc, char** argv) -> int {
  LOG(INFO) << "FFVI 2023 tty client started.\n";
  (void)argc;
  (void)argv;
  ffvi::FFVI ffvi;
  return 0;
}
