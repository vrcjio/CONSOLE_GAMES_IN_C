#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// 🧾 Function to show game rules
void showRules()
{
    system("cls");
    printf("📜 GAME RULES 📜\n\n");
    printf("🔸 Maintain your pet's Hunger, Energy, and Happiness levels.\n");
    printf("🔹 If Hunger reaches 10, your pet starves and it's Game Over.\n");
    printf("🔹 If Energy drops to 1 or below, your pet is exhausted and it's Game Over.\n");
    printf("🔹 If Happiness drops to 2 or below, your pet is too sad and it's Game Over.\n");
    printf("🏆 Reach 20 Happiness to Win!\n\n");
    printf("💡 Actions:\n");
    printf("  1. Feed     -> -3 Hunger, +1 Happiness\n");
    printf("  2. Task     -> -2 Energy, +2 or -1 Happiness\n");
    printf("  3. Sleep    -> +3 Energy, +1 Hunger\n");
    printf("\n🔁 Hunger increases every 2 turns, and random events may reduce Energy.\n");
    printf("\nPress any key to return to game...\n");
    printf("\n=====================================================");
    printf("\nYour also know the rules pls Enter any key");
    getch();
    system("cls");
}

int runRandomTime()
{
    int min = 1000, max = 5000;
    int time = min + rand() % (max - min + 1);

    char spinner[] = {'-', '\\', '|', '/'};
    int steps = time / 1000;

    for (int i = 0; i < steps; i++)
    {
        system("cls");
        printf("⏳ Waiting... %c\n", spinner[i % 4]);
        Sleep(1000);
    }

    return time;
}

int main()
{
    int hunger = 5, happiness = 5, energy = 5;
    int choice;
    char *tasks[] = {
        "Fetch the ball",
        "Dance performance",
        "Solve a puzzle",
        "Find hiddne Toy"};
    int numOfTask = sizeof(tasks) / sizeof(tasks[0]);
    srand(time(0));
    showRules();

    do
    {

        static int turn = 0;
        turn++;
        if (turn % 2 == 0)
            hunger++;
        if (rand() % 10 >= 7)
        {
            happiness--;
        }
        energy--;

        // random bad event chance(20% chance)
        int badEvent = rand() % 5; // 0 to 4
        if (badEvent == 0)
        {
            printf("\n⚠️ Oh no! Your pet cought a cold. -2 energy.\n");
            energy -= 2;
        }
        // win or lose check
        if (happiness >= 20)
        {
            printf("\n🎉 Your pet is extremly happy! You Win!\n");
            break;
        }
        else if (hunger >= 10)
        {
            printf("\n💀 Your pet is straving! Game Over!\n");
            break;
        }
        else if (energy <= 1)
        {
            printf("\n💤 Your pet is exhausted! Game Over!\n");
            break;
        }
        else if (happiness <= 2)
        {
            printf("\n😢 Your pet is very sad! Game Over!\n");
            break;
        }

        printf("\nStatus = > Hunger: %d, Happiness: %d, Energy: %d\n", hunger, happiness, energy);
        printf("\n1. Feed (Decreases Hunger, Increases Happiness)\n");
        printf("2. Do a Task (Increases Happiness, Decreases Energy)\n");
        printf("3. Sleep (Increases Energy, Increases Hunger)\n");
        printf("4. Exit\n");

        printf("\nChoose an action: ");
        scanf("%d", &choice);

        runRandomTime();

        switch (choice)
        {
        case 1:
            hunger -= 3;
            happiness++;
            printf("\n🍗 Pet is fed!\n");
            break;

        case 2:
            if (energy >= 2)
            {
                int taskIndex = rand() % numOfTask;
                printf("\n📝 Task: %s\n", tasks[taskIndex]);
                printf("Pet is doing task...\n");
                Sleep(1000);
                int success = rand() % 100;
                if (success >= 10)
                {
                    happiness += 2;
                    printf("✅ Task complete! +2 happiness, -2 Energy\n");
                }
                else
                {
                    happiness -= 1;
                    printf("❌ Task Failed! -1 Happiness\n");
                }
                energy -= 2;
            }
            else
            {
                printf("\n⚠️ Not enough to do task! Let the pet sleep.\n");
            }
            break;

        case 3:
            energy += 3;
            hunger += 1;
            printf("\n😴 Pet is sleeping... +3 Energy, +1 Hunger\n");
            break;

        case 4:
            printf("\n👋 Goodbye!\n");
            break;

        default:
            printf("\n❌ Invalid Option!\n");
        }
        system("cls");

    } while (choice != 4);

    return 0;
}