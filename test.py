import torch

torch.ops.load_library("build/ogiLib.dylib")
print(torch.ops.ogiLib.make_rand(2, 3))