#pragma once

namespace mpi {
  class Context final {
  public:
      Context() noexcept;

      Context(int& argc, char**& argv) noexcept;

      ~Context() noexcept;

      Context(Context const&) = delete;

      Context& operator=(Context const&) = delete;

      Context(Context&&) = default;

      Context& operator=(Context&&) = default;

      [[nodiscard]] int world_rank() const;

      [[nodiscard]] int world_size() const;

      void abort(int status);

      void send(int value, int receiver_rank);

      int receive(int sender_rank);
  };
}
