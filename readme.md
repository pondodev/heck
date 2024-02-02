# heck

because sometimes writing c can be heck, but it doesn't have to be.

## what is heck?

you ever find yourself writing some stuff and copy pasting it over to every single project you do? i know i have, and
it's kinda annoying! especially since to bring those improvements over to all my projects requires that i copy my
changes around everywhere, and i'm super lazy.

enter: heck.

this is really just a personal c library i'll add to over time as i see the need. i don't really intend for this to be
some big library to fit everyone's needs, but if you find use in it then i'm real glad :)

## usage

you will need `cmake` to build heck. here's a list of commands you'll need to know:
```
cmake -B build              # generate build files to directory `/build`
cmake --build build         # build heck
cmake --build build -- test # run unit tests
```

there are also the following options you can set when generating the build files:
```
-DENABLE_TESTS=[ON/OFF] # enable or disable testing. default is `ON`
```

**TODO: how to link it to your project lmao**

## features

list to come!

