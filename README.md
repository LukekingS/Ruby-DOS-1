# Ruby-DOS-1
RubyOS, RubyDOS or simply R-DOS is a project for an operating system based on the x86 architecture.


## Members

  - @LukekingS (hardware)
  - tetex7 (software)
  - @blm16 (software)


## Motivation

Starting from a personal interest of technology itself, over a few months, I have already compiled a large collection of vintage items. Those range from old rotary telephones, mechanical typewriters and mechanical calculators over to electronic retro technology such as a KAYPRO II, various HIGHSCREEN devices and Commodore computers.

With this in mind, I and a few buddies of mine thought to ourselves that maybe we could start to build our very own version of an *old* computer like those mentioned above from scratch; the machine as well as the operating system.


### Quick Disclaimer

This is a free-time project only which is worked on by three people from time to time, so don't expect and rapid or large updates here. But please follow us on our journey if you're interested nevertheless. :)


### Organisation

  - /code/ will include all code-related files and documents
  - /hardware/ will include all hardware-related files and documents
  - /images/ will include all other images
  - if necessary, other sub-folders will be created accordingly


## General ideas

### Requirements

  - 80186 / 80286 / 80386 CPU architecture
    - most likely settling on the i386
  - Z80 I/O processor
  - built-in keyboard
    - possibly PS/2 compatible
  - ISA board expansion
  - 5¼" floppy compatibility
  - VGA, MDA
    - preferred method is VGA or at least composite via cinch connector


### Start-up Screens

  - Here are some start-up screen ideas we've come up with

```
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
|                                |
|                                |
|                                |
|                                |
|        no system present       |
|     insert system boot disk    |
|                                |
|                                |
|                                |
|                                |
|                                |
 ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
```
  - this one's inspired by CP/M

```
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
|                                |
|         Welcome to ...         |
|                                |
|                                |
|                  /\            |
|                 /  \           |
|           Ruby | OS |          |
|                 \__/           |
|                                |
|                                |
|                                |
 ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
```
  - this one's an own creation

```
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
|   |¯¯¯¯¯¯¯¯¯|     |¯¯¯¯¯¯¯¯|   |
|   | [F]iles |     | [D]ate |   |
|   |_________|     |________|   |
|                                |
|   |¯¯¯¯¯¯¯¯¯¯¯¯|  |¯¯¯¯¯¯¯¯|   |
|   | [S]ettings |  | [T]ime |   |
|   |____________|  |________|   |
|                                |
|                                |
| 01/01/1980  RubyOS       00:04 |
|                                |
 ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
```
  - this one's inspired by a Triumph Adler notebook computer

![Triumph Adler Workstation set-up screen](/images/triumph-adler-startup-screen.jpg)

  1. A picture taken of a Triumph Adler Walkstation notebook computer from my collection whose set-up menu is being slightly represented in the rendition above.


### Hardware Design

For a general shape of the device, the monitor is going to sit on top of a wedge-shaped housing made of sheet metal. It will have a 5¼" floppy drive built into its right-hand side. On the backside, there will be serial and parallel ports and other periphery options, as well as the power connector and switch. The monitor will be monochrome with brightness and contrast adjustments on either the backside or (preferably) the front panel (much like old IBM monitors).

![Ruby 1 sketch, concept art](/images/Ruby_I.png)

  2. Here's a side-by-side overview sketch of this machine. Keep in mind that this design isn't set in stone but instead might change later on in the progress of this project.


