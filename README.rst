Embrava BlyncLight
==================

|pypi| |license| |python|

**blynclight** is a Python 3 package that provides bindings for the
`Embrava`_ BlyncLight family of products. These bindings have been
tested on MacOS and Linux using an Embrava V30 USB connected light.


Install
-------

0. Install ``libusb`` for your platform:

.. code:: bash

          (rpm Linux distros)# yum install libusb 
          (apt Linux distros)# apt-get install libusb-1.0
          (macOS using brew) $ brew install libusb

1. pip

.. code:: bash

	  $ pip3 install blynclight

2. Clone the repo

.. code:: bash

	  $ git clone https://github.com/JnyJny/blynclight.git
	  $ cd blynclight; pip3 install -e .

  
Uninstall
---------

.. code:: bash

	  $ pip3 uninstall blynclight

	  

Usage
-----

Once installed, the BlyncLight is yours to command!

.. code:: python

	from blynclight import BlyncLight

	light = BlyncLight.first_light()

	red, blue, green = (255, 0, 0), (0, 255, 0), (0, 0, 255)
	
	light.color = green           # the light is off and green
	light.on = True               # the light is on and green
	light.flash = True            # the light is on, flashing and green
	light.color = red             # the light is on, flashing and red
	light.flash = False           # the light is on and red
	light.bright = False          # the light is on, dim and red
	light.color = blue            # the light is on, dim and blue
	light.bright = True           # the light is on and blue
	light.on = False              # the light is off and blue
	
More examples can be found in the contrib directory.


.. |pypi| image:: https://img.shields.io/pypi/v/blynclight.svg?style=flat-square&label=version
    :target: https://pypi.org/pypi/blynclight
    :alt: Latest version released on PyPi

.. |python| image:: https://img.shields.io/pypi/pyversions/blynclight.svg?style=flat-square
   :target: https://pypi.org/project/blynclight/
   :alt: Python Versions	  

.. |license| image:: https://img.shields.io/badge/license-apache-blue.svg?style=flat-square
    :target: https://github.com/erikoshaughnessy/blynclight/blob/master/LICENSE
    :alt: Apache license version 2.0  

.. _Embrava: https://embrava.com


