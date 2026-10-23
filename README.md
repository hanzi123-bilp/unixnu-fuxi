<p align="center">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="assets/logo-dark.svg">
    <source media="(prefers-color-scheme: light)" srcset="assets/logo-light.svg">
    <img alt="UniXNU" src="assets/logo-light.svg" width="200">
  </picture>
</p>

<p align="center">
  <a href="https://unixnu.com"><img alt="Documentation" src="https://img.shields.io/badge/docs-unixnu.com-2A5BD7?logo=readthedocs&logoColor=white"></a>
  <a href="https://t.me/unixnu"><img alt="Telegram" src="https://img.shields.io/badge/Telegram-@unixnu-26A5E4?logo=telegram&logoColor=white"></a>
  <a href="https://qun.qq.com/universal-share/share?ac=1&authKey=Pubz23DOCY76nxjlGuSms2zesk4jRvas4zrXJRYk7omf7CprXbGQigLEI%2BCoYR8D&busi_data=eyJncm91cENvZGUiOiIxMTI2MTE2NzU5IiwidG9rZW4iOiJwSHJsUDN1UnN2Vi8yM210TjJRbzBIcERmcUpyOS9lb0hHVVpadWdvVFdScVpSYUFLT1YzTk5TWC9mN2xWYmtIIiwidWluIjoiMzE1MTEwOTc0MSJ9&data=_cJgr-jX9yJ2-GXwVjRN5FOhDyk5B-HAfIk5LSunbW_XkkmKqNXbpH33wzP93J0p9DI1fbjgBUrUfTVhwDcxjg&svctype=4&tempid=h5_group_info"><img alt="QQ Group" src="https://img.shields.io/badge/QQ%20Group-join-12B7F5?logo=qq&logoColor=white"></a>
  <a href="https://x.com/unixnu"><img alt="X" src="https://img.shields.io/badge/X-@unixnu-000000?logo=x&logoColor=white"></a>
</p>

# UniXNU-fuxi

Device repository for the Xiaomi Pad 6S Pro (fuxi, SM8550). It holds the board file, kernel defconfig, device scripts, drivers and package.

🎉 **News:** The native Metal GPU driver is fully working on fuxi. The render server composites the system UI through the Adreno 740, and listed processes get their own Metal devices.

- [Documentation](https://unixnu.com)
- [Device page](https://unixnu.com/devices/fuxi)
- [Porting guide](https://unixnu.com/porting/)
- [Build](https://unixnu.com/building)

Firmware: [uefi-fuxi](https://github.com/UniXNU/uefi-fuxi).

Build with the `unixnu` driver of [UniXNU](https://github.com/UniXNU/UniXNU). Clone both repositories with `--recurse-submodules`; `unixnu fetch` also updates the module submodules.

## Build

Run these commands from the UniXNU checkout. The device repository is `../UniXNU-fuxi`.

```sh
./unixnu defconfig fuxi_defconfig -D ../UniXNU-fuxi
./unixnu fetch
./unixnu ipsw fetch
./unixnu build kernel
./unixnu build package
./unixnu build firmware --uefi ../uefi-fuxi
cd ../uefi-fuxi
python3 uefi-fuxi/scripts/bootimage.py
```

The [device page](https://unixnu.com/devices/fuxi#build) adds the userdata image and the Data seed growth commands. The platform seed, trust cache and Data seed are device inputs. Use `--owner-trust-cache <bundle>` for an owner-signed bundle.

Without a Mac, run the kernel and userdata steps in the [macOS runner workflow](https://github.com/UniXNU/UniXNU/actions/workflows/macos.yml). The [build guide](https://unixnu.com/building#macos-runner) lists its inputs.

## Device support

The original iPadOS userland runs from the IPSW; the home screen and Settings are reached. This table records user-facing device support.

| Feature | State | Notes |
| --- | --- | --- |
| Touch | ✅ | Novatek NT36532E |
| Display | ✅ | |
| UFS | ✅ | Native UFS root |
| Wi-Fi | ❌ | |
| Bluetooth | ❌ | |
| Camera | ❌ | |
| GPU | ✅ | Native Metal, GPU compositing, per-process devices and exported pipeline caches |
| USB | ❌ | |
| Audio | ❌ | |
| Sensors | ❌ | |
| Battery driver | ❌ | |
| MiPPS | ❌ | |
| Suspend and resume | ❌ | |

✅ available, ⚠️ partial, ❌ not available. The GPU details are in the [Adreno 740 driver](https://unixnu.com/drivers/native-adreno) page.

## License

BSD-2-Clause-Patent. See [LICENSE](LICENSE).
