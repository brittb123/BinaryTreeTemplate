#include "TreeNode.h"
#include <iostream>
#include "raylib.h"

TreeNode::TreeNode(int value)
{
	m_value = value;
}

void TreeNode::draw(int x, int y, bool selected)
{
	// An array to store the characters to print to the screen
	static char buffer[10];

	// Converts the m_value to an int to store in the array
	sprintf(buffer, "%d", m_value);

	// Draws a circle that is yellow for the outline
	DrawCircle(x, y, 30, YELLOW);

	// If selected is true a new green circle is made for the center of the outline
	if (selected)
		DrawCircle(x, y, 28, GREEN);

	// If it is not selected a circle is drawn in a black color to resemble not selected
	else
		DrawCircle(x, y, 28, BLACK);

	// Draws the text in the center of the circle
	DrawText(buffer, x - 12, y - 12, 12, WHITE);
}