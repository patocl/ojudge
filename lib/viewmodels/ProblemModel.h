/*********************************************************************
 * Copyright (C) 2020 Miguel Revilla Rodríguez
 *                    and the OJudge Platform project contributors
 *
 * This file is part of the OJudge Platform
 *
 * Read the LICENSE file for information on license terms
 *********************************************************************/

#ifndef PROBLEMMODEL_H
#define PROBLEMMODEL_H

#include <Wt/WAbstractTableModel.h>

class DBModel ;

class ProblemModel : public Wt::WAbstractTableModel {
public:
	ProblemModel(DBModel *dbmodel) ;
	virtual int columnCount(const Wt::WModelIndex& parent = Wt::WModelIndex()) const override;
	virtual int rowCount(const Wt::WModelIndex& parent = Wt::WModelIndex()) const override;
	virtual Wt::cpp17::any data(const Wt::WModelIndex& index, Wt::ItemDataRole role = Wt::ItemDataRole::Display) const override;
	virtual Wt::cpp17::any headerData(int section, Wt::Orientation orientation = Wt::Orientation::Horizontal, Wt::ItemDataRole role = Wt::ItemDataRole::Display) const override;

private:
	void refresh();
	void populateData();
	DBModel *dbmodel_ ;

	struct ProblemData {
		long long id ;
		std::string title ;
		std::string categories ;
	};

	std::map<int,ProblemData> problemData_;
};

#endif // PROBLEMMODEL_H