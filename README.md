# Example with WebAssembly source maps

## Prepare emcc

- Install emsdk and activate incoming version.
- Update emscript with https://gist.github.com/yurydelendik/bd36e8d470a2bdd2238a15556083363b
- If needed, build binaryen and specify BINARYEN_ROOT in the ~/.emscripten
- If needed, `source emsdk_env.sh`

(see also https://github.com/kripken/emscripten/pull/5335)

## Build

```
make
```

## Testing

Open in Firefox Nightly via local server at http://localhost:8000/pi.html

(At the moment try with `devtools.debugger.new-debugger-frontend=false`)
