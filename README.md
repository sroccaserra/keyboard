ZSA Moonlander layout, builds with the ZSA QMK fork:

- <https://github.com/zsa/qmk_firmware/>

Initial layout version:

- <https://configure.zsa.io/moonlander/layouts/jXKZa/mDJvX/0>

## Build

- Clone the QMK fork above, and set branch to firmware21 if it is not the
  default branch
- Follow the installation instructions given here:
    - <https://docs.qmk.fm/>
    - <https://docs.qmk.fm/#/newbs_getting_started?id=set-up-your-environment>
- Make a link or copy the keymap from this repo to the corresponding directory
  in the `qmk_firmware` cloned above.
- From the root of the `qmk_firmware` directory, `make moonlander:sroccaserra`
  to build the firmware.
- `make moonlander:sroccaserra:flash` to flash the firmware.

Example (check docs above):

```shell
$ git clone git@github.com:zsa/qmk_firmware.git
$ git submodule init
$ git submodule update
$ ln -s ~/Developer/github/keyboard/moonlander/keymaps/sroccaserra keyboards/moonlander/keymaps/
$ make moonlander:sroccaserra:flash
```

## Combos

- <https://docs.qmk.fm/#/keycodes>
- <https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md>
- <https://github.com/qmk/qmk_firmware/pull/8591>
- <https://blog.gboards.ca/2020/02/adventures-in-obscure-c-features-2020.html>
