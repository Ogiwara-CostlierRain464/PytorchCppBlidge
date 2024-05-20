1. PytorchとCMakeをインストール
2. 共有ライブラリの作成
```
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH="$(python -c 'import torch.utils; print(torch.utils.cmake_prefix_path)')" ..
make -j
```
この手順により、ogiLibが生成される。

3. 共有ライブラリを読み込んでTorchの関数を呼び出し
```
python3 test.py
```

ここで、macOSでは共有ライブラリの拡張子はdylibとなっているので、test.py内ではogiLib.dylibを読み込んでいる。OSに合わせて適宜拡張子を変える必要がある。


参考： https://pytorch.org/tutorials/advanced/torch_script_custom_ops.html#registering-the-custom-operator-with-torchscript

