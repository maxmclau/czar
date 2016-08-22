# Czar [inactive]

[Atmel Lightweight Mesh](http://www.atmel.com/tools/lightweight_mesh.aspx) abstraction layer written in C++.

#### Install

```Shell
$ cd ~/Documents/Arduino/libraries
$ git clone https://github.com/moa/czar.git
```

#### Usage

```Arduino
void setup() {
    Czar.setup(0, true);
}
    
void loop() {
    Czar.loop();
}
```

#### Configuration

Don't forgot about the lwm.h file in your build - referenced in the lwm [**`documentation`**](https://github.com/moa/lwm#configuration).

#### License

[**`MIT`**](LICENSE)
