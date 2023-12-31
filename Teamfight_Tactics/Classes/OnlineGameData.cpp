#include "OnlineGameData.h"

OnlineGameData onlineGameData;

void OnlineGameData::getData()
{
	m_blood = MyLittleHero.getCurBlood();
	fightNum = MyLittleHero.m_fightArray->num;
	playerNum = MyLittleHero.m_playerArray->num;
	for (int i = 0; i < fightNum; i++)
	{
		hero* temp = (hero*)MyLittleHero.m_fightArray->arr[i];
		m_ArrayTypes.push_back(temp->getType());
		m_ArrayX.push_back(temp->getPositionX());
		m_ArrayY.push_back(temp->getPositionY());
	}
	for (int i = 0; i < playerNum; i++)
	{
		hero* temp = (hero*)MyLittleHero.m_playerArray->arr[i];
		m_ArrayTypes.push_back(temp->getType());
		m_ArrayX.push_back(temp->getPositionX());
		m_ArrayY.push_back(temp->getPositionY());
	}
}

std::string OnlineGameData::serializeGameData() {
	std::ostringstream out;

	out << m_blood << ";" << fightNum << ";" << playerNum << ";";

	for (size_t i = 0; i < fightNum; ++i) {
		out << m_ArrayTypes[i] << ",";
		out << m_ArrayX[i] << ",";
		out << m_ArrayY[i] << ";";
	}

	for (size_t i = fightNum; i < fightNum + playerNum; ++i) {
		out << m_ArrayTypes[i] << ",";
		out << m_ArrayX[i] << ",";
		out << m_ArrayY[i] << ";";
	}

	return out.str();
}

OnlineGameData OnlineGameData::deserializeGameData(const std::string& serializedData) {
	OnlineGameData data;
	std::istringstream in(serializedData);
	std::string segment;

	std::getline(in, segment, ';');
	m_blood = std::stoi(segment);

	std::getline(in, segment, ';');
	fightNum = std::stoi(segment);

	std::getline(in, segment, ';');
	playerNum = std::stoi(segment);

	while (std::getline(in, segment, ';')) {
		std::istringstream segmentStream(segment);
		std::string value;

		std::getline(segmentStream, value, ',');
		m_ArrayTypes.push_back(std::stoi(value));

		std::getline(segmentStream, value, ',');
		m_ArrayX.push_back(std::stof(value));

		std::getline(segmentStream, value, ',');
		m_ArrayY.push_back(std::stof(value));
	}

	return data;
}

void OnlineGameData::toPlayer2Data()
{
	//清空player2的数据
	ccArrayRemoveAllObjects(player2data.m_fightArray);
	ccArrayRemoveAllObjects(player2data.m_playerArray);

	player2data.setCurBlood(m_blood);

	for (int i = 0; i < fightNum; i++)
	{
		hero* temp = CreateHero(m_ArrayTypes[i]);
		temp->setPosition(positionToEnemyPosition(Vec2(m_ArrayX[i], m_ArrayY[i])));
		ccArrayAppendObject(player2data.m_fightArray, temp);

	}
	for (int i = 0; i < playerNum; i++)
	{
		hero* temp = CreateHero(m_ArrayTypes[i + fightNum]);
		temp->setPosition(positionToEnemyPosition(Vec2(m_ArrayX[i + fightNum], m_ArrayY[i + fightNum])));
		ccArrayAppendObject(player2data.m_playerArray, temp);
	}
}