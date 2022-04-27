# CS202_Fall2021_PSU
Background:
When beginning with this project, the first thing to keep in mind is that we are no longer working
on CS163 programs! In CS163, we were concerned about creating Abstract Data Types. Instead,
this term we will be focusing on how to create Object Oriented Solutions. An ADT may be part of
that solution – but it certainly shouldn’t be the primary focus. Instead, plan and develop classes
that have specific “jobs”, where one class is derived from a more general class, whenever
appropriate. We will learn to “push up the common” and “derive the differences”. We will be
working in situations where there are multiple classes, so you will want to focus on dividing the
design into smaller components that have specific jobs working together to solve the problem.
Every assignment this term needs to have at least 5 classes. Divide up the work that each class
needs to do. If each class performs a small specific job, then as a collective, a much larger problem
can be solved. Object Oriented Programming is about delegating responsibilities. Avoid the over
use of functions to “give” another class hidden data (these are called “getters” and are typically not
object oriented). If you give data to another class, it means that the other class will need to know
all about the details of how to process that data, causing a duplication of effort. Instead, each class
should be responsible for managing their own data. Instead of giving your data away – implement
the functionality necessary to process that data based on what the client class would have needed
to do.
This term, we will begin by guiding you through object oriented techniques by focusing your
attention first on the core component of the problem that manages the underling data. Then we will
move to the next phase where we begin to write classes that use that hierarchy, implementing the
assigned data structures.
Overview of the Problem:
I heard a news report yesterday that Tesla will be offering drivers of their vehicles
software to allow for fully automated “hands free” driving contingent on their driving
performance. It got me to think about what it will be like in 20 or 30 years. Instead of
having cars with cameras to determine where they can change lanes or stop, the cars will
talk to each other to communicate when it is safe to change lanes. Stop lights will talk to
cars to let them know if it is time to stop or if there is an obstruction (or person) in the
crosswalk or intersection. Garbage cans will talk to Recycling trucks to let them know
where to pick them up and when they are full. Bus stops will talk to busses as to when it
is time to stop or if a passenger needs off. Can you even imagine?

CS202 Fall 2021 Programming Assignment #1
Your job for this first program is to find three types of smart devices that will need to
communicate with one another in a futuristic smart city. You will be picking three
different smart devices, two of which need to be forms of transportation.

Program #1 Specifics
For Program #1, you will be creating an object oriented program that will provide three
different types of smart devices that will make a smart city automated (such as with trash
pick up, cars, busses, and other such as stop lights, cross walks, garbage cans etc.).
Making this Object Oriented: Create a Design and first Progress Submission
You will want to first think about breaking this down into a series of classes and create
them independent of the entire problem. We will push up the common elements of the
three processes you have selected and derive the differences, making for a hierarchy. This
hierarchy should not include the data structure. Instead, think about one item (such as
one car, one trash can, one stop light).
Look at the common elements of these classes – push them up to a common base class
and derive the differences. Anything that is similar between these or other classes that
you write only once. Keep classes small and functions small. A large class or function
means that the problem has not yet been broken down into its basic components (objects).
The first progress submission should address this hierarchy without the data structures
integrated. To limit the scope, each smart device must have at least 3 meaningful methods
besides constructors, destructors, and display functions. You can have input methods!
Arrays of Characters vs Strings

Your base and at least one derived class must have dynamic memory supported such as
arrays of characters for practice. All other use of string data should be represented by the
STL’s string class.

Creating a Collection of Objects: Second Progress Submission
There are two data structures you will.

• An Array of linear linked lists (e.g., for the location of the smart devices)
• A Circular linked list of one type of your smart devices for testing purposes
• Add one other use of a STL data structure – such as an Array or a Vector
Implementation of the data structures requires full support of insert, removal, display,
retrieval, and remove-all. All repetitive code for these functions must be implemented
recursively.
