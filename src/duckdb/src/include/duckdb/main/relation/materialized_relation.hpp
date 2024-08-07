//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/main/relation/materialized_relation.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/main/relation.hpp"
#include "duckdb/parser/parsed_expression.hpp"

namespace duckdb {

class MaterializedRelation : public Relation {
public:
	MaterializedRelation(const shared_ptr<ClientContext> &context, unique_ptr<ColumnDataCollection> &&collection,
	                     vector<string> names, string alias = "materialized");
	vector<ColumnDefinition> columns;
	string alias;
	shared_ptr<ColumnDataCollection> collection;

public:
	const vector<ColumnDefinition> &Columns() override;
	string ToString(idx_t depth) override;
	string GetAlias() override;
	unique_ptr<TableRef> GetTableRef() override;
	unique_ptr<QueryNode> GetQueryNode() override;
};

} // namespace duckdb
