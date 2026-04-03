#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

// void printHeader( std::string title ){
// 	std::cout << "\n==========================================" << std::endl;
// 	std::cout << "         " << title << std::endl;
// 	std::cout << "==========================================" << std::endl;
// }

// int main(){

// 	printHeader("1. CONSTRUCTION & DESTRUCTION ORDER");
// 	{
// 		std::cout << "--- Creating DiamondTrap 'D-03' ---" << std::endl;
// 		std::cout << "Required: Clap -> Scav -> Frag -> Diamond" << std::endl;
// 		DiamondTrap diamon("D-03");
// 		std::cout << "\n--- Destruction starts here ---" << std::endl;
// 		std::cout << "Required: Diamond -> Frag -> Scav -> Clap" << std::endl;
// 	}

// 	printHeader("2. IDENTITY & WHOAMI TEST");
// 	{
// 		DiamondTrap diamond("Loki");
// 		std::cout << "Required: Name should be 'Loki', Clap name 'Loki_clap_name'" << std::endl;
// 		diamond.whoAmI();
// 	}

// 	printHeader("3. STATS & ATTACK DELEGATION");
// 	{
// 		DiamondTrap diamond("Monster");

// 		std::cout << "\n--- Testing ScavTrap::attack() delegation ---" << std::endl;
// 		std::cout << "Look at the message below. It should look like ScavTrap's attack." << std::endl;
// 		diamond.attack("a training dummy");

// 		std::cout << "\n--- Testing Energy Points (from ScavTrap: 50) ---" << std::endl;
// 		std::cout << "Starting energy should be 50. Attacking 50 times..." << std::endl;
// 		for (int i = 0; i < 51; ++i) {
// 			diamond.attack("target");
// 		}
// 		std::cout << diamond.getEnergyPoints() << " energy points should be left (0 if it depleted)." << std::endl;
// 		std::cout << "The 51st attack should fail due to energy depletion:" << std::endl;
// 		diamond.attack("one last target");

// 		std::cout << "\n--- Testing Hit Points (from FragTrap: 100) ---" << std::endl;
// 		diamond.beRepaired(10); // Should fail due to energy, but if it had energy:
// 		// Let's check death at 100.
// 		diamond.takeDamage(99);
// 		std::cout << "Should have 1 HP left." << std::endl;
// 		diamond.takeDamage(1);
// 		std::cout << "Should be dead now." << std::endl;
// 		diamond.whoAmI(); // Should show death message if implemented
// 	}

// 	printHeader("4. SPECIAL ABILITIES INHERITANCE");
// 	{
// 		DiamondTrap diamond("Hybrid");
// 		std::cout << "Can it guard the gate (Scav)? ";
// 		diamond.guardGate();
// 		std::cout << "Can it high five (Frag)? ";
// 		diamond.highFivesGuys();
// 	}

// 	printHeader("5. ORTHODOX CANONICAL FORM");
// 	{
// 		DiamondTrap original("Alpha");
// 		DiamondTrap copy(original);
// 		DiamondTrap assigned("Beta");
// 		assigned = original;

// 		std::cout << "Original identity:" << std::endl;
// 		original.whoAmI();
// 		std::cout << "Copy identity:" << std::endl;
// 		copy.whoAmI();
// 		std::cout << "Assigned identity:" << std::endl;
// 		assigned.whoAmI();
// 	}
// 	return 0;
// }


int main() {
    std::cout << "\n=========================================" << std::endl;
    std::cout << "  CRASH TEST 1: The Self-Assignment Trap " << std::endl;
    std::cout << "=========================================\n" << std::endl;

    DiamondTrap selfTest("Narcissus");

    // We create a reference to the object to trick the compiler
    DiamondTrap& sneakyRef = selfTest;

    // The compiler allows this, but at runtime, they are the exact same object!
    selfTest = sneakyRef;

    selfTest.whoAmI();

    std::cout << "\n=========================================" << std::endl;
    std::cout << "  CRASH TEST 2: Heap Allocation & Pointers " << std::endl;
    std::cout << "=========================================\n" << std::endl;

    /*
     * Creating objects on the heap using 'new'.
     * You must manually manage the memory and use '->' instead of '.'.
     */
    DiamondTrap* heapTrap = new DiamondTrap("Heap_Monster");
    heapTrap->attack("a memory leak");
    delete heapTrap; // Should cleanly call destructors in reverse order.

    std::cout << "\n=========================================" << std::endl;
    std::cout << "  CRASH TEST 3: The Polymorphism Trap " << std::endl;
    std::cout << "=========================================\n" << std::endl;

    /* * DANGER ZONE: We store a derived object in a base class pointer.
     * This is a core concept of Module 04, but it breaks Module 03 code easily.
     */
    ClapTrap* basePtr = new DiamondTrap("Poly_Monster");
	basePtr->attack("a polymorphic target"); // Calls ClapTrap's attack, not DiamondTrap's!

    // Watch your console output carefully on this next line!
    delete basePtr;

    std::cout << "\n=========================================" << std::endl;
    std::cout << "  CRASH TEST 4: Array of Object Pointers " << std::endl;
    std::cout << "=========================================\n" << std::endl;

    // Testing massive memory allocation and deallocation
    DiamondTrap* army[10];
    for(int i = 0; i < 10; i++) {
        army[i] = new DiamondTrap("Clone");
    }
    for(int i = 0; i < 10; i++) {
        delete army[i];
    }

    std::cout << "\nSurvived the crash tests!" << std::endl;
    return 0;
}
