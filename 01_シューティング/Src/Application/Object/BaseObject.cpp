#include "BaseObject.h"

void BaseObject::Update()
{
}

void BaseObject::Draw()
{
}

void BaseObject::Init()
{
}

void BaseObject::Release()
{
}

void BaseObject::OnHit()
{
}

void BaseObject::SetTexture(std::string _fileName)
{
	m_tex.Load(_fileName); // このプログラムでは使用しない
}
