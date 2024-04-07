#pragma once
#include "gtest/gtest.h"
#include "ConverterJSON.h"

struct TestConverterJSON: public testing::Test
{
	ConverterJSON *converter;
	void SetUp() override { converter = new ConverterJSON; }
	void TearDown() override { delete converter; }
};

TEST_F(TestConverterJSON, testGetTextDocuments)
{
	//Quantity documents > 0
	EXPECT_GT(converter->getTextDocuments().size(), 0);
}

TEST_F(TestConverterJSON, testGetResponseLimit)
{
	//the maxResponses field into config.json must be greater than zero
	EXPECT_GT(converter->getResponsesLimit(), 0);
}

TEST_F(TestConverterJSON, testGetRequests)
{
	//The number of requests must be greater than zero
	EXPECT_GT(converter->getRequests().size(), 0);
}