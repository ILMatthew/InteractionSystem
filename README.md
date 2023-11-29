"# InteractionSystem" 

Generic plug and play interaction system.

Two components are responsable for trigger the interactions:
- The InteractorComponent is responsable for sending calls to the object you want to interact with. Can be added to a character or pawn and used alongside custom logic to select an object and trigger the interaction.
- The InteractableComponents enable interactions with an object. It has a list of avaiable interaction and it triggers the interaction logic when called.

Finally there are interaction object.
This are simple objects that get created, execute their logic and then destroyed. They first check if the interaction is valid and, if it is, proced with the interaction.
They have callback for both successfull and unsuccefull interaction to allow characters/pawn to execute custom logic (like animations) based on the result.
Creating new interactions is as simple as creating a new blueprint derived from BP_Interaction and overriding the CustomCheck and CustomLogic functions.

![InteractionSystemExemple](https://github.com/ILMatthew/MyPlugins/assets/46683546/3e38cfe7-7d30-47cd-9b5c-03cafc65a124)
