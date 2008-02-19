/***************************************************************************
 *   Copyright (C) 2005-08 by the Quassel Project                          *
 *   devel@quassel-irc.org                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) version 3.                                           *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _IRCSERVERHANDLER_H_
#define _IRCSERVERHANDLER_H_

#include "basichandler.h"

class IrcServerHandler : public BasicHandler {
  Q_OBJECT

public:
  IrcServerHandler(NetworkConnection *parent);
  ~IrcServerHandler();

  void handleServerMsg(QByteArray rawMsg);

public slots:
  void handleJoin(const QString &prefix, const QList<QByteArray> &params);
  void handleKick(const QString &prefix, const QList<QByteArray> &params);
  void handleMode(const QString &prefix, const QList<QByteArray> &params);
  void handleNick(const QString &prefix, const QList<QByteArray> &params);
  void handleNotice(const QString &prefix, const QList<QByteArray> &params);
  void handlePart(const QString &prefix, const QList<QByteArray> &params);
  void handlePing(const QString &prefix, const QList<QByteArray> &params);
  void handlePrivmsg(const QString &prefix, const QList<QByteArray> &params);
  void handleQuit(const QString &prefix, const QList<QByteArray> &params);
  void handleTopic(const QString &prefix, const QList<QByteArray> &params);

  void handle001(const QString &prefix, const QList<QByteArray> &params);   // RPL_WELCOME
  void handle005(const QString &prefix, const QList<QByteArray> &params);   // RPL_ISUPPORT
  void handle301(const QString &prefix, const QList<QByteArray> &params);   // RPL_AWAY
  void handle311(const QString &prefix, const QList<QByteArray> &params);   // RPL_WHOISUSER
  void handle312(const QString &prefix, const QList<QByteArray> &params);   // RPL_WHOISSERVER
  void handle313(const QString &prefix, const QList<QByteArray> &params);   // RPL_WHOISOPERATOR
  void handle314(const QString &prefix, const QList<QByteArray> &params);   // RPL_WHOWASUSER
  void handle315(const QString &prefix, const QList<QByteArray> &params);   // RPL_ENDOFWHO
  void handle317(const QString &prefix, const QList<QByteArray> &params);   // RPL_WHOISIDLE
  void handle318(const QString &prefix, const QList<QByteArray> &params);   // RPL_ENDOFWHOIS
  void handle319(const QString &prefix, const QList<QByteArray> &params);   // RPL_WHOISCHANNELS
  void handle331(const QString &prefix, const QList<QByteArray> &params);   // RPL_NOTOPIC
  void handle332(const QString &prefix, const QList<QByteArray> &params);   // RPL_TOPIC
  void handle333(const QString &prefix, const QList<QByteArray> &params);   // Topic set by...
  void handle352(const QString &prefix, const QList<QByteArray> &params);   //  RPL_WHOREPLY
  void handle353(const QString &prefix, const QList<QByteArray> &params);   // RPL_NAMREPLY
  void handle369(const QString &prefix, const QList<QByteArray> &params);   // RPL_ENDOFWHOWAS
  void handle432(const QString &prefix, const QList<QByteArray> &params);   // ERR_ERRONEUSNICKNAME
  void handle433(const QString &prefix, const QList<QByteArray> &params);   // ERR_NICKNAMEINUSE

  void defaultHandler(QString cmd, const QString &prefix, const QList<QByteArray> &params);

signals:
  void nickChanged(const QString &newNick, const QString &oldNick); // this signal is inteded to rename query buffers in the storage backend
  
private:
  void tryNextNick(const QString &errnick);
  bool _whois;
};


#endif
