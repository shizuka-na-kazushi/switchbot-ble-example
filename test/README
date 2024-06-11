

このレポジトリは、BLE (Bluetooth low energy)のプロトコルにて[SwitchBot の開閉センサー](https://www.switchbot.jp/products/switchbot-contact-sensor)のセンサー値を読み取るサンプルプログラムです。
ライブラリの状態にはなっていません。実動作をさせるプログラムの参考コードとして御覧ください。

## プロトコル

プロトコルは、SwitchBotが公開している以下のドキュメントを参考にしています。

* [SwitchBotAPI-BLE](https://github.com/OpenWonderLabs/SwitchBotAPI-BLE/tree/latest)

Advertisement packetの値のみを読み取っています。

## 開発環境

|項目 | 内容|
|----|----|
|ハードウェア| ESP32 WROOM ([WayinTopの ESP32開発ボード](https://www.amazon.co.jp/WayinTop-ESP32%E9%96%8B%E7%99%BA%E3%83%9C%E3%83%BC%E3%83%89-BLE%E3%83%A2%E3%82%B8%E3%83%A5%E3%83%BC%E3%83%AB-ESP-WROOM-32%E5%AE%9F%E8%A3%85%E6%B8%88%E3%81%BF-%E5%B0%82%E7%94%A8USB%E3%82%B1%E3%83%BC%E3%83%96%E3%83%AB%E4%BB%98%E3%81%8D/dp/B086QKRY25/ref=sr_1_1_sspa?adgrpid=76724662928&dib=eyJ2IjoiMSJ9.8lEPmELupkjhj9mBWmLU0TZnDuerMGIDtcC9xYBZse5CbrpsYbLFhZFtiOOnDDAdu-TzbQ7iGPAVwtLR4hIciHOY_QYnby3VhKrUuPSOmmNOLTY5-SwlIpoioT-NCYuNPvM4QN3epjCmTDBxbZmtMhUx1ZPMAwkWBt_JDN32wASSAa9wsLJ-IEawYk9MfvS9mnsmqGzBXizqD33QmA9dKDJhlUvkPoWEjCTd_fEQOnUxKo-Q4fo7neDUNVLPPWHmieYZPC3RgP6nNlMgBRJor-C32JMNOxGREE6YMjv-uOw.3AfESlyJ5l7pviawB4BbFAhK93iEAXSZqo4V7tPAR6k&dib_tag=se&hvadid=651189104593&hvdev=c&hvlocphy=1009297&hvnetw=g&hvqmt=e&hvrand=17388821036778772563&hvtargid=kwd-850628270119&hydadcr=10234_13607025&jp-ad-ap=0&keywords=amazon+esp32&qid=1718070093&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1))|
|ソフトウェア| Visual Studio Code + PlatformIO extension|

## プラットフォーム

ESP32のArduino開発環境を使用しています。BLE通信には、BLEDevice.hと関連モジュールを使用。

* platform = espressif32
* board = esp32dev
* framework = arduino


## 動作について

ドアが開くとGPIO-12番につながったLEDがひかり、センサーの前に人がいるとGPIO-13につながったLEDがひかる、というシンプルなものです。

SensorActions.h/.cppを書き換えるとセンサーの状態に応じたさまざまな動作が可能になります。

## 使い方に関する注意

SwitchBot開閉センサーのMACアドレスを決め打ちでソースコードに埋め込んでいます。

DeviceAddr.h内の以下の箇所に正しいMACアドレスを埋め込んで下さい。
```C
static BLEAddress contactSensorAddr("xx:xx:xx:xx:xx:xx");
```
MACアドレスは、SwitchBotアプリで調べることができます。

## 補足

[SwitchBot人感センサー](https://www.switchbot.jp/products/switchbot-motion-sensor)に関するコード（クラス）も含んでいます。(SwitchbotDevice.h参照)
使い方は開閉センサーと同様です。

