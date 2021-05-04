#include "MPI.hxx"

#include <mpi.h>

#include <cassert>
#include <memory>

namespace mpi {
  Context::Context() noexcept
  {
    auto const result = MPI_Init(nullptr, nullptr);
    assert(result==MPI_SUCCESS);
  }

  Context::Context(int& argc, char**& argv) noexcept
  {
    auto const result = MPI_Init(std::addressof(argc), std::addressof(argv));
    assert(result==MPI_SUCCESS);
  }

  Context::~Context() noexcept
  {
    MPI_Finalize();
  }

  int Context::world_rank() const
  {
    int value{};
    MPI_Comm_rank(MPI_COMM_WORLD, &value);
    return value;
  }

  int Context::world_size() const
  {
    int value{};
    MPI_Comm_size(MPI_COMM_WORLD, &value);
    return value;
  }

  void Context::abort(int status)
  {
    MPI_Abort(MPI_COMM_WORLD, status);
  }

  void Context::send(int value, int receiver_rank)
  {
    MPI_Send(&value, 1, MPI_INT, receiver_rank, 0, MPI_COMM_WORLD);
  }

  int Context::receive(int sender_rank)
  {
    int value{};
    MPI_Recv(&value, 1, MPI_INT, sender_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    return value;
  }
}
