#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

extern "C" {
auto ffi_mutate_my_packet(std::uint8_t *data, std::size_t len) -> void;
}

struct Packet {
  std::vector<char> data;
};

namespace ffi {

auto mutate_my_packet(Packet &packet) -> void {
  ffi_mutate_my_packet(reinterpret_cast<std::uint8_t *>(packet.data.data()),
                       packet.data.size());
}

} // namespace ffi

auto main() -> int {
  std::string message = "RelcomeToRust";

  auto packet = Packet{
      .data = std::vector<char>(message.begin(), message.end()),
  };

  ffi::mutate_my_packet(packet);

  message = std::string(packet.data.begin(), packet.data.end());

  std::cout << message << std::endl;
}
