# Problem
Consider the abstract class Military Object. A military facility can be visited by spies who can do damage or steal classified papers.

Let's consider the General Staff class, which is a descendant of the Military Object class and where senior officers are concentrated and classified papers are stored.

Also, we will consider the Military Base class, which concentrates personnel and equipment.

Implement the Visitor programming pattern to model the process of visiting military facilities by spies. To do this, describe the abstract class Spy, which contains abstract methods for visiting different types of military facilities.

Consider two types of spies - Secret Agent and Saboteur - descendants of the Spy class. The purpose of visiting a military facility of the Secret Agent class is to collect or steal secret information. The purpose of a visit to a military facility by a Saboteur spy is to destroy secret documents, destroy personnel and equipment of the military facility.