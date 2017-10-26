# SDL2 with Haskell on OS X

I have assumed that you have installed SDL2 headers and libraries (Homebrew is
by far the easiest way to do this) and that you have also installed the sdl2
package.

## SDL2 Installation with Homebrew

    $ brew install sdl2

That should be all you need.

## Cabal installation of the Haskell binding for SDL2

    $ cabal install sdl2

This of course --might-- take ages as cabal downloads almost as many
dependencies as a Node.js project. Hopefully it will just work, if it doesn't
well you will have to look around for your own way out of cabal hell. Sorry.

# Building

Couldn't be simpler, just use the following:

    $ ghc --make sdl01.hs
    $ ./sdl01

It sits there until you press ESC three times or click the close window button
or use CMD+Q.

