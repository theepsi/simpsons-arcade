#include "core.h"
#include "character.h"
#include "marge.h"
#include "margeIdleState.h"
#include "margeJumpAttackState.h"

MargeJumpAttackState::MargeJumpAttackState()
{
}

MargeJumpAttackState::~MargeJumpAttackState()
{
}

void MargeJumpAttackState::Update(Character& player)
{
	if (player.position.y >= 0) {
		player.position.y = 0;
		player.ChangeState(new MargeIdleState, "idle");
	}
	else {
		if (player.flipped)
			player.position.x -= 5;
		else
			player.position.x += 5;
		player.position.y += 5;
	}
}
