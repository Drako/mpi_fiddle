#include "MPI.hxx"

#include <iostream>

static int const MAX_PINGS = 10;

// Ping Pong Example
int main(int argc, char** argv)
{
  mpi::Context ctx{argc, argv};
  int const world_rank = ctx.world_rank();
  int const world_size = ctx.world_size();

  int const partner_rank = (world_rank+1) & 1;

  if (world_size!=2) {
    std::cerr << "World size must be 2 for " << *argv << std::endl;
    ctx.abort(1);
  }

  int ping_count = 0;
  while (ping_count<MAX_PINGS) {
    if (world_rank==(ping_count & 1)) {
      ctx.send(++ping_count, partner_rank);
      std::cout << world_rank << ": Incremented ping_count to " << ping_count << " and sent it to " << partner_rank
                << std::endl;
    }
    else {
      ping_count = ctx.receive(partner_rank);
      std::cout << world_rank << ": Received ping_count " << ping_count << " from " << partner_rank << std::endl;
    }
  }

  return 0;
}
