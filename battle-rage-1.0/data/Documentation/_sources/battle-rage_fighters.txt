:program:`battle-rage` fighters
===============================

:ref:`All fighters <Fighters-gallery>` have some properties:

+ ``Speed``

+ ``Aggressiveness``

+ ``Force``

+ ``Resistance``

.. _property-speed:

Speed
-----

The speed indicate the speed the fighter ``moves`` **forward** or **backward**.

And how much *(speed / 3.75)* the fighter **advance** in direction to the **adversary** when he **give a kick**.

:note: The **speed** values are comprise between: [**10**-**15**].

.. _property-aggressiveness:

Aggressiveness
--------------

This property is only take into account when the fighter is the computer.

And indicate how aggresive the fighter is.

:note: The aggressiveness value is a percent.

.. _property-force:

Force
-----

The force indicate how much damage the fighter inflict to his adversary minus the adversary resistance.

:note: The fighter force is comprise between [**0.80**-**1.30**].

.. _property-resistance:

Resistance
----------

The fighter resistance indicate how much life points the fighter he will lose when he receive a kick.

:note: The resistance value is comprise between: [**0.75**-**1.25**].

.. note::

  When the fighter kick the ass of his adversary and this one is not protected

  The life points from the adversary are reduce in this manner:

  ::

    ([Value of the kick] × [force]) - ([Resistance common value] × [resistance]) ;         
 