#include <iostream>
#include <torch/torch.h>

torch::Tensor make_rand(int64_t x, int64_t y){
    return torch::rand({x, y});
}

TORCH_LIBRARY(ogiLib, m) {
  m.def("make_rand", make_rand);
}

