.. _joysticks:

Joystick(s) logic of :program:`battle-rage`
+++++++++++++++++++++++++++++++++++++++++++

.. The analogique directional pad is recommended but you can maybe use the digital as well.

.. Sorry for the the non RL (R1), RB (R2), LF (L1), LB (L2) buttons but I get not enough image to provide combinations withn this buttons.

The joystick plan:
------------------

|

  .. image:: ./_images/joystick_battle-rage.png

|

:program:`battle-rage` joystick usage
-------------------------------------

  For playing :program:`battle-rage` you only need the the **4** buttons :guilabel:`&A`, :guilabel:`&B`, :guilabel:`&Y` and :guilabel:`&Y` and a **directional pad** (stick).

  The button at the top of the joystick (``RF``, ``RB``, ``LF``, ``LB``) aren't used.

  You can use the **digital** stick (*directional pad*), **which is recommended**, as well as the **analogical** stick.

  :warning: I can't guarantee you that you can use twice stick at the same time once your joystick configured.

.. _joystick-rules:

:program:`battle-rage` and his joystick rules
---------------------------------------------

  :program:`battle-rage` has some rules for playing with the joystick.

  According to the fact that you have **2 hands** and **2 foots** (exclude for the physic handicap).

  :program:`battle-rage` follow **the same logic** for the *joystick* buttons **logic**:

  + The **back hand** from your fighter is **activate** by ``pressing`` the :guilabel:`&A` button from the *joystick*.

  + The **front hand** from your fighter  is **activate** by ``pressing`` the :guilabel:`&X` button from the *joystick*.

  + The **front foot** from your fighter is **activate** by ``pressing`` the :guilabel:`&B` button from the *joystick*.

  + The **back foot** from your fighter is **activate** by ``pressing`` the :guilabel:`&Y` button from the *joystick*.

  :note: You can sea that like a cross which **X** axis is are the foots and the **Y** axis the hands.

  You can use **combinations** by adding a direction from the **directional keypad** to the used button.

  This will generate different kicks for every combination.

  **Finally** all combination make sens, *per example*:

  Pressing the **Up** arrow and an **hand button** will produce an **uppercut**,

  and pressing the :**Back arrow** and a **foot kick** will produce a **return foot kick**.

  .. warning::

    because ``nothing is perfect`` it can happen that a combination don't really

    represent what it should like explain above.

    But **I guarantee** that it really **doesn't happen often** and that the replacement **is near from your expecting**.

    And some kicks have fallbacks: this mean that 2 differents combination can give the same kick: not often.

    All according the fighter.


  :note: Because it's easier to press a button instead of using a combination the combinations inflict more damage.

  .. note::

    This logic is follow for every **joystick** model since you have to configure your **joystick** first.

    But you can **reconfigure** your **joystick** if you make a mistake during the configuration phase.


The different joysticks models handling
---------------------------------------

  :program:`battle-rage` doesn't claim to take in charge every different joystick model of the world but:

  .. note::

    :program:`battle-rage` does the best for taking in charge the most of different joystick models.

    And you must pass through a *joystick configuration phase*, which is oblige,

    every time you **plug a new joystick model**.

    **Not** every time you plug your(s) *joystick* to **play the game** !

    :warning: To know that every time you plug a new joystick model you will have to configure it.

    That's better for all: the game logic, you, conversation about battle rage,...

    Because it permit to set a precise combination set, not in according differents joysticks models mess, but according to the game.

Advice:
-------

  ``You must better plug the joystick before starting the game.``

  Else you will be notify about the problem and be invited to plug a joystick before really starting the game.

  ``And if you plan to play with 2 users plug 2 joystick before gaming.``

  But you if you don't have plug 2 joysticks you will be invited to do so...

  **Sorry** but my *joystick handler* doesn't handle the ``plug-in plug-off`` of *joysticks*,

  so the free hot plug of *joystick(s)* is not permit with :program:`battle-rage`.

If the joystick configuration fail.
-----------------------------------

  If you have bad luck and your *joystick* model is really not compatible with battle rage, havoc.

  Else, ``if you made an error``, you can try to reconfigure your *joystick* again by using the configure joystick menu item.

  :note: `Sea the technical note for further informations <technical-notes-about-joystick-config>`_.

.. _technical-notes-about-joystick-config:

Technical notes about joystick handle.
--------------------------------------

  Internally :program:`battle-rage` highly suppose that the buttons :guilabel:`&A`, :guilabel:`&B`, :guilabel:`&X` and :guilabel:`&Y` have all a value comprise between included *[0-3]* like the most *joysticks* does.

  Internally :program:`battle-rage` suppose that directional pad is implemented as 2 axis (:guilabel:`&B` and :guilabel:`&Y` for the **X** axis and :guilabel:`&A` and :guilabel:`&X` for the **Y** axis).

  But you can predict **nor** the ``SDL2``: if an axis number will be the **X** or the **Y** but most common joystick use ``0`` for **X** and ``1`` for **Y**...

  But the sticks: analogical and digital are taking in charge, because with :program:`battle-rage` you must configure you joystick the first time you plug it.

  And the big problem is that some joystick doesn't respect at all this rules.

  I can only test this values which are right for my test *joysticks* (2 joysticks which works differently).

  So if your *joystick* work otherwise than with this values for this set of buttons or axis **it won't work at all !**

  This fact is coming from that I use an ``Input_Handler`` written by **Shaun Mitchell**, for his book ``SDL Game Development (june 2013) [Packt Publishing]``.

  I **enhance** this ``Input_Handler`` to take in charge the most of joystick possible: The most common.

  Even if the base joystick for **Shaun Mitchell** (an ``X Box 360`` **joystick**) won't work with :program:`battle rage` because of the fail of one axe.

  But you can play :program:`battle-rage` with an ``X Box 360`` **joystick** but the **Y** axis won't work !

  :note: Great thanks to **Shaun Mitchell** for his book and code writing and his code.