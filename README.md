# c-type-checking

I like type safety, but I also like C. I hear STB talk a lot about typesafe C structures, particularly hash maps. My previous typesafe hash map is pretty ugly in implementation, but has pretty good usage.
However, I think that this new method I just found (inspired by the `DeferLoop` implementation that I saw in the [raddebugger](https://github.com/EpicGamesExt/raddebugger) codebase) using the
[comma syntax](https://en.wikipedia.org/wiki/Comma_operator), which I previously had no idea of, may revolutionise my typesafe implementations.

## Improvements

- I would like to be able to handle reference lvalues without requiring a different macro. This is not a hude deal, as the macro would only be used in a small number of function implementations, but still.
- Also, the compiler messages are pretty verbose due to the nested macros, but are still better than most of the stuff you get from C++ template errors.
