# Image Screens mod

This mod adds buildable Image Screens of several sizes and aspect ratios.
The screens can be configured to display either a static image downloaded from a web,
or a slideshow of web images.


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


## Aspect ratio

You can display images of any aspect ratio in any screen.
If the aspect ratio of the image does not match that of the screen,
the image will be stretched to fill the whole screen.


## Copy and paste

The image screens support Satisfactory's copy and paste of building properties.
Press Ctrl+C to copy screen properties and Ctrl+V to paste the same image to a different screen.

When you sample an image screen building with the middle mouse button
and place its copy, it will be displaying the same image or slideshow.


## Mod configuration

The mod supports a few configuration properties.
They can be set in the Mod section of the main or pause menu.
Any changes made will affect existing screens immediately, game reload is not needed.

In multiplayer, the options set on the host (or dedicated server) are used.
Changing options on the client has no effect.


## Errors

When an error occurs (e.g. an image cannot be downloaded), the screen displays a red X.
Interact with the screen to show the UI that contains information about the last error.


## Network activity

The purpose of this mod is to allow displaying images downloaded from the internet.
The mod only downloads images or slideshows from URLs entered by the player.
The mod does not access any other URLs on its own.

The mod supports multiplayer.
A screen built or modified by one player will be displaying to all players in the session.
If the URL is an image file, all clients will download and display the image.
If the URL is a text file, the server (host or DS) will download that file,
and all clients will then be downloading and displaying the images in that slideshow.


## Programming documentation

Detailed [programming documentation](Doc/Programming.md) is available.
