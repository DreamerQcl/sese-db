-- MariaDB dump 10.19-11.1.0-MariaDB, for Win64 (AMD64)
--
-- Host: 127.0.0.1    Database: db_test
-- ------------------------------------------------------
-- Server version	11.1.0-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

CREATE DATABASE db_test;

USE db_test;

--
-- Table structure for table `tb_delete`
--

DROP TABLE IF EXISTS `tb_delete`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tb_delete` (
  `id` int(11) NOT NULL,
  `name` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='用于删除测试';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_delete`
--

LOCK TABLES `tb_delete` WRITE;
/*!40000 ALTER TABLE `tb_delete` DISABLE KEYS */;
INSERT INTO `tb_delete` VALUES
(1,'foo'),
(2,'bar');
/*!40000 ALTER TABLE `tb_delete` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_insert`
--

DROP TABLE IF EXISTS `tb_insert`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tb_insert` (
  `id` int(11) NOT NULL,
  `name` varchar(32) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='用于插入测试';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_insert`
--

LOCK TABLES `tb_insert` WRITE;
/*!40000 ALTER TABLE `tb_insert` DISABLE KEYS */;
INSERT INTO `tb_insert` VALUES
(1,'foo'),
(2,'bar');
/*!40000 ALTER TABLE `tb_insert` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_query`
--

DROP TABLE IF EXISTS `tb_query`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tb_query` (
  `id` int(11) NOT NULL,
  `name` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='此表用于查询';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_query`
--

LOCK TABLES `tb_query` WRITE;
/*!40000 ALTER TABLE `tb_query` DISABLE KEYS */;
INSERT INTO `tb_query` VALUES
(1,'foo'),
(2,'bar');
/*!40000 ALTER TABLE `tb_query` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_stmt_delete`
--

DROP TABLE IF EXISTS `tb_stmt_delete`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tb_stmt_delete` (
  `id` int(11) NOT NULL,
  `name` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='用于预处理语句的删除测试';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_stmt_delete`
--

LOCK TABLES `tb_stmt_delete` WRITE;
/*!40000 ALTER TABLE `tb_stmt_delete` DISABLE KEYS */;
INSERT INTO `tb_stmt_delete` VALUES
(1,'foo'),
(2,'bar');
/*!40000 ALTER TABLE `tb_stmt_delete` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_stmt_insert`
--

DROP TABLE IF EXISTS `tb_stmt_insert`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tb_stmt_insert` (
  `id` int(11) NOT NULL,
  `name` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='用于预处理语句的插入测试';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_stmt_insert`
--

LOCK TABLES `tb_stmt_insert` WRITE;
/*!40000 ALTER TABLE `tb_stmt_insert` DISABLE KEYS */;
INSERT INTO `tb_stmt_insert` VALUES
(1,'foo'),
(2,'bar');
/*!40000 ALTER TABLE `tb_stmt_insert` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_stmt_query`
--

DROP TABLE IF EXISTS `tb_stmt_query`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tb_stmt_query` (
  `id` int(11) NOT NULL,
  `name` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='用于预处理语句的查询测试';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_stmt_query`
--

LOCK TABLES `tb_stmt_query` WRITE;
/*!40000 ALTER TABLE `tb_stmt_query` DISABLE KEYS */;
INSERT INTO `tb_stmt_query` VALUES
(1,'foo'),
(2,'bar');
/*!40000 ALTER TABLE `tb_stmt_query` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_stmt_update`
--

DROP TABLE IF EXISTS `tb_stmt_update`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tb_stmt_update` (
  `id` int(11) NOT NULL,
  `name` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='用于预处理语句的更新';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_stmt_update`
--

LOCK TABLES `tb_stmt_update` WRITE;
/*!40000 ALTER TABLE `tb_stmt_update` DISABLE KEYS */;
INSERT INTO `tb_stmt_update` VALUES
(1,'foo'),
(2,'bar');
/*!40000 ALTER TABLE `tb_stmt_update` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_update`
--

DROP TABLE IF EXISTS `tb_update`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tb_update` (
  `id` int(11) NOT NULL,
  `name` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='用于更新测试';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_update`
--

LOCK TABLES `tb_update` WRITE;
/*!40000 ALTER TABLE `tb_update` DISABLE KEYS */;
INSERT INTO `tb_update` VALUES
(1,'foo'),
(2,'bar');
/*!40000 ALTER TABLE `tb_update` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-05-23 21:14:59