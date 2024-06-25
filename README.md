# EVW-008_mqtt

![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/InzynierDomu/EVW-008_mqtt/main.yml?logo=github&style=flat-square)
![GitHub release (latest SemVer)](https://img.shields.io/github/v/release/InzynierDomu/Relay_mqtt?style=flat-square)
<a href="https://inzynierdomu.github.io/EVW-008_mqtt/">![GitHub docs deployments](https://img.shields.io/github/deployments/InzynierDomu/Relay_mqtt/github-pages?label=docs&logo=BookStack&logoColor=white&style=flat-square)</a>
<a href="https://discord.gg/KmW6mHdg">![Discord](https://img.shields.io/discord/815929748882587688?logo=discord&logoColor=green&style=flat-square)</a>
![GitHub](https://img.shields.io/github/license/InzynierDomu/Relay_mqtt?style=flat-square)
<a href="https://tipo.live/p/inzynierdomu">![support](https://img.shields.io/badge/support-tipo.live-yellow?style=flat-square)</a>

## Desciption

Simple project to controll relays on EVW-008 board with ESP8266.It can be useful for home automation or other projects. Will work great with Nod-RED, Home Assistant, Domoticz, etc.

📖 <a href="https://www.inzynierdomu.pl/evw-008-i-mqtt-czyli-devboard-idealny-do-prostej-automatyki/">note about project</a>
📽️ <a href="https://youtube.com/shorts/Eb1-dHuqsug">short video with project</a>

<div align="center">
<h2>💖 Support</h2>

<p>If any of my projects have helped you in your work, studies, or simply made your day better, please consider supporting my work. <strong><a href="https://tipo.live/p/inzynierdomu">LINK</a></strong></p>
</div>

If you are looking for a project for MQTT and a simple ESP8266 board like nodeMCU or Wemos, you can find my project here: [LINK](https://github.com/InzynierDomu/Relay_mqtt).

## Configuration

To ensure this project works for you, you must modify the src/config.h file to match your own settings.
You need the ssid and password of the network to which the mqtt borker is connected.
You need also provide the ip of the mqtt broker, preferably it should also be protected with a password and username that must be provided.
Mqtt id should be unique for each device connected to a given mqtt broker.
The subscription topic is also an example. + means it works on all subtopics. Subtopics for each output can also be changed.

## IDE

The project is prepared for the Platform IO environment. A video on how to install such an environment can be watched on this [video PL](https://youtu.be/Em9NuebT2Kc).
<br><br>

If you don't have an environment and don't want to prepare it, you can use the autodeply.bat script, which will configure everything and, if the board is connected to the computer, will load the project. You need only instaled Python and an Internet connection.

Formatting is done using clang-format. The description of the tool configuration is in the [video PL](https://youtu.be/xxuaOG0WjIE).
<br><br>
