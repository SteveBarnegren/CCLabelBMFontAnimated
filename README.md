CCLabelBMFontAnimated
=====================

CCLabelBMFontAnimated is a label class for Cocos2d-x, inheriting for LabelBMFont. The primary feature of this class is to easily enable the running of Cocos2d actions on the individual letters of a label.

Actions can be run on an individual letter, on all letters simultaneously, on each letter sequentially, or on each letter sequentially in reverse. When running actions sequentially, a duration can be specified.

There is also the option to get the label to remove itself on completion of the action (useful, for instance, if the action is a fly past, or animate out), and also the option to pass in a CallFunc action, to be executed when the full action has completed.

See the following YouTube video for an example of what can be done with this class: http://youtu.be/Ku8kq8CY_vk
