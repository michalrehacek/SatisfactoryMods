This mod adds buildable Image Screens of several sizes and aspect ratios.
The screens can be configured to display either a static image downloaded from a web,
or a slideshow of web images.


## Showcase

![URL edit box](https://raw.githubusercontent.com/michalrehacek/SatisfactoryMods/refs/heads/main/ImageScreens/Doc/img/widget.jpg)

![Landscape screen](https://raw.githubusercontent.com/michalrehacek/SatisfactoryMods/refs/heads/main/ImageScreens/Doc/img/landscape.jpg)


## Unlocking

Image Screens are locked behing a hub milestone in Tier 1.
The screens are meant to be available early and with basic resources.


## Building

When built, the screen displays a default placeholder image.
To set up a real image, interace with the screen as with any other building.

To display a static image, paste an URL of an image in JPG or PNG format to the edit box.
As a shortcut, the Paste button will paste an URL from the clipboard and confirm the change.
If the image downloaded successfully, the screen will start displaying the specified image.

To display a slideshow, paste an URL of a text file.
The text file needs to contain names of images on the same web server
in the same directory or subdirectory.

The screen only supports images or slideshows downloaded from a web server.
Displaying files from your computer is not supported. Other mods exist that will do that.


## Network activity

The purpose of this mod is to allow displaying images downloaded from the internet.
The mod only downloads images or slideshows from URLs entered by the player.
The mod does not access any other URLs on its own.

The mod supports multiplayer.
A screen built or modified by one player will be displaying to all players in the session.
If the URL is an image file, all clients will download and display the image.
If the URL is a text file, the server (host or DS) will download that file,
and all clients will then be downloading and displaying the images in that slideshow.


## Further documentation

You can find more documentation, including detailed programming documentation,
in the mod's [Github repository](https://github.com/michalrehacek/SatisfactoryMods).


## About me

I am not a serious modder.
I created the Image Screens mod because I wanted to learn Unreal Engine.

I am a professional game developer and I tried to document the mods well,
so that they can be used as a learning material.
The mods contain programming documentation which explains how each mod is made,
why some features are implemented the way they are, etc.

I am not too active in the Satisfactory modding discord.
My Discord username is `michal.rehacek`.
However, the best way to reach me is my email: rehacek AT the mail from google.
If you want to report a problem with the mod, you can use the Github issues page or email.
