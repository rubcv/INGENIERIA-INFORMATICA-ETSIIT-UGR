-- phpMyAdmin SQL Dump
-- version 4.8.0.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 08-06-2018 a las 15:13:11
-- Versión del servidor: 10.1.32-MariaDB
-- Versión de PHP: 7.2.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `rubencav1718`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `admins`
--

CREATE TABLE `admins` (
  `nombre` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `apellidos` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  `telefono` int(9) NOT NULL,
  `email` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `clave_cifrada` varchar(100) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `admins`
--

INSERT INTO `admins` (`nombre`, `apellidos`, `telefono`, `email`, `clave_cifrada`) VALUES
('Nuevo', 'Admin', 123456789, 'nuevo@gmail.com', 'MTIzNDU2'),
('Ruben', '1', 999999999, 'prueb22a@gmail.com', ''),
('Ruben', 'SASD', 123456789, 'prueba@gmail.com', 'MTIzNA==');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `articulos`
--

CREATE TABLE `articulos` (
  `foto` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  `nombre` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  `precio` decimal(9,0) NOT NULL,
  `tipo` varchar(50) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `articulos`
--

INSERT INTO `articulos` (`foto`, `nombre`, `precio`, `tipo`) VALUES
('imagenes_subidas/articulos/snoop1.jpg', 'Discos (Ed. Especial)', '50', 'merch'),
('imagenes_subidas/articulos/last-meal.jpg', 'Last Meal', '25', 'disco'),
('imagenes_subidas/articulos/snoop2.jpg', 'Merchandising', '30', 'merch'),
('imagenes_subidas/articulos/neva-left.jpg', 'Neva Left', '25', 'disco');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `biografia`
--

CREATE TABLE `biografia` (
  `id` int(10) UNSIGNED NOT NULL,
  `fecha` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `texto` varchar(10000) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `biografia`
--

INSERT INTO `biografia` (`id`, `fecha`, `texto`) VALUES
(6, '2017', 'Calvin Cordozar Broadus Jr. (Long Beach, 20 de octubre de 1971), mÃ¡s conocido como Snoop Dogg o Snoop Lion,2â€‹ es un rapero, cantante, productor y actor estadounidense. Ha sido uno de los artistas de hip-hop con mÃ¡s Ã©xito del West Coast rap ademÃ¡s de uno de los mÃ¡s notables protegidos del productor Dr. Dre. Fue miembro de la banda Crips cuando estudiaba en el instituto. AlgÃºn tiempo despuÃ©s de su graduaciÃ³n, fue arrestado por posesiÃ³n de cocaÃ­na y pasÃ³ seis meses en la cÃ¡rcel del Condado de Wayside. Su carrera musical comenzÃ³ en 1992 despuÃ©s de ser puesto en libertad, cuando fue descubierto por Dr. Dre, con quien colaborÃ³ en temas de su disco debut en solitario The Chronic, y en la canciÃ³n principal de la banda sonora de el videoclip Deep Cover.'),
(7, '1996', 'Snoop Dogg fue al instituto de Long Beach Polytechnic High School, donde coincidiÃ³ con Cameron Diaz, y su incursiÃ³n inicial en la vida pÃºblica fue debido a su participaciÃ³n en trÃ¡ficos de drogas, aunque a una escala relativamente pequeÃ±a. Snoop fue miembro de la banda local Rollin\' 20 Crips. Sin embargo Snoop fue presionado para integrarse en el mundo de la mÃºsica y dejar a un lado las ventas de drogas en las calles. Posteriormente, Snoop grabÃ³ unas cintas caseras con su primo Nate Dogg y su amigo Warren G (hermanastro de Dr. Dre que en esos tiempos trabajaba para N.W.A.). En un principio, Lil\' 1/2 Dead, primo de Nate, y por lo tal de Snoop, formaba tambiÃ©n parte del grupo llamado 213, nombrado asÃ­ debido a que ese era el por entonces prefijo local de Long Beach. Esto era en parte en homenaje al grupo 413 de Richie Rich, conocido asÃ­ por el por entonces tambiÃ©n prefijo local de Oakland, California. \r\n                ');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `canciones`
--

CREATE TABLE `canciones` (
  `disco` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `nombre` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `duracion` varchar(10) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `canciones`
--

INSERT INTO `canciones` (`disco`, `nombre`, `duracion`) VALUES
('Doggystyle', 'Dogg Collar', '4:02'),
('Doggystyle', 'Doggy Dogg World', '3:36'),
('Doggystyle', 'Gin And Juice', '3:02'),
('Neva Left', 'm.a.c.a', '5:30'),
('Doggystyle', 'Murder Was The Case', '4:28'),
('Neva Left', 'neva left', '4:20'),
('Neva Left', 'snoop', '4:20');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `componentes`
--

CREATE TABLE `componentes` (
  `nombre` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `nacimiento` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `foto` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `bio_componente` varchar(500) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `componentes`
--

INSERT INTO `componentes` (`nombre`, `nacimiento`, `foto`, `bio_componente`) VALUES
('Snoop Dogg', '2018-05-31', 'imagenes_subidas/componentes/bio.jpg', 'West Coast rap leyenda Snoop Dogg has come a long way since being discovered by Dr. Dre in the early 1990. \r\nAs impressive as he was when guesting on Dreâ€™s The Chronic in 1992, few could have guessed \r\nheâ€™d go on to global fame, tens of millions of record sales, and a career in movies and TV. And thatâ€™s only part \r\nof the story, from battles with the law to reinvention as a reggae artist. Snoopâ€™s story isnâ€™t finished yet, 4 \r\nand who knows what this Long Beach native will do next? \r\n  ');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `conciertos`
--

CREATE TABLE `conciertos` (
  `cartel` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `fecha` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `hora` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `lugar` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `nombre` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `descripcion` varchar(500) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `conciertos`
--

INSERT INTO `conciertos` (`cartel`, `fecha`, `hora`, `lugar`, `nombre`, `descripcion`) VALUES
('imagenes_subidas/conciertos/concert2.jpg', '2018-06-14', '19:30', 'Londres', 'Granada sound', 'Increible concierto de Snoop Dogg en Granada sound otro aÃ±o mÃ¡s 2018 para impresionar a los fans'),
('imagenes_subidas/conciertos/concert1.jpg', '2018-12-13', '22:22', 'California', 'Tomorrowland', ' Concierto de Snoop Dogg en California para el festival de Tomorrowland como todos los aÃ±os llega para impresionar a los fans con su espectÃ¡culo y su increible tono barÃ­tono de orquesta \r\n                ');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `discos`
--

CREATE TABLE `discos` (
  `foto` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `nombre` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  `year_s` int(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `discos`
--

INSERT INTO `discos` (`foto`, `nombre`, `year_s`) VALUES
('imagenes_subidas/discos/doggystyle.jpg', 'Doggystyle', 1996),
('imagenes_subidas/discos/neva-left.jpg', 'Neva Left', 2017);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `gestores`
--

CREATE TABLE `gestores` (
  `nombre` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `apellidos` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  `telefono` int(9) NOT NULL,
  `email` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `clave_cifrada` varchar(100) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `gestores`
--

INSERT INTO `gestores` (`nombre`, `apellidos`, `telefono`, `email`, `clave_cifrada`) VALUES
('Armando ', 'Casas', 123456789, 'prueb1a@gmail.com', ''),
('Batman', 'Superman', 123456789, 'prueba@gmail.com', '');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `pedidos`
--

CREATE TABLE `pedidos` (
  `correo_cliente` varchar(50) COLLATE utf8_spanish_ci DEFAULT NULL,
  `fecha_pedido` date DEFAULT NULL,
  `fecha_gest` date DEFAULT NULL,
  `nombre_gest` varchar(50) COLLATE utf8_spanish_ci DEFAULT NULL,
  `apellidos_gest` varchar(50) COLLATE utf8_spanish_ci DEFAULT NULL,
  `estado` varchar(20) COLLATE utf8_spanish_ci DEFAULT NULL,
  `email_enviado` varchar(1000) COLLATE utf8_spanish_ci DEFAULT NULL,
  `nombre_producto` varchar(50) COLLATE utf8_spanish_ci DEFAULT NULL,
  `id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `pedidos`
--

INSERT INTO `pedidos` (`correo_cliente`, `fecha_pedido`, `fecha_gest`, `nombre_gest`, `apellidos_gest`, `estado`, `email_enviado`, `nombre_producto`, `id`) VALUES
('prueba@gmail.com', '2018-06-08', '0000-00-00', 'NULL', 'NULL', 'pendiente', 'NULL', '||Discos (Ed. Especial) || Last Meal || ', 1),
('admin@gmail.com', '2018-06-08', '0000-00-00', 'NULL', 'NULL', 'pendiente', 'NULL', '||Neva Left || ', 2),
('prueba@gmail.com', '2018-06-08', '0000-00-00', 'NULL', 'NULL', 'pendiente', 'NULL', '||Doggystyle || ', 3),
('prueba@gmail.com', '2018-06-08', '0000-00-00', 'NULL', 'NULL', 'pendiente', 'NULL', '||Doggystyle || ', 4),
('prueba@gmail.com', '2018-06-08', '0000-00-00', 'NULL', 'NULL', 'pendiente', 'NULL', '||NevaLeft || ', 5);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuarios`
--

CREATE TABLE `usuarios` (
  `email` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `clave_cifrada` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  `tipo` varchar(20) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `usuarios`
--

INSERT INTO `usuarios` (`email`, `clave_cifrada`, `tipo`) VALUES
('nuevo@gmail.com', 'MTIzNDU2', 'admin'),
('prueb1a@gmail.com', 'MTIzNA==', 'gestor'),
('prueb2a@gmail.com', 'MTIzNA==', 'admin'),
('prueba@gmail.com', 'MTIzNA==', 'admin');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuarios_p4`
--

CREATE TABLE `usuarios_p4` (
  `email` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `nombre` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `apellidos` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `clave_cifrada` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  `tipo` varchar(30) COLLATE utf8_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `usuarios_p4`
--

INSERT INTO `usuarios_p4` (`email`, `nombre`, `apellidos`, `clave_cifrada`, `tipo`) VALUES
('admin@gmail.com', 'admin', 'admin', 'cDEy', 'admin'),
('n@gmail.com', 'n', 'n', 'cDEy', 'admin'),
('n2@gmail.com', 'n', 'n', 'cDEy', 'normal'),
('n3@gmail.com', 'n', 'n', 'cDEy', 'normal'),
('n4@gmail.com', 'n', 'n', 'cDEy', 'normal'),
('prueba@gmail.com', 'prueba', 'prueba', 'cDEy', 'normal');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `admins`
--
ALTER TABLE `admins`
  ADD PRIMARY KEY (`email`);

--
-- Indices de la tabla `articulos`
--
ALTER TABLE `articulos`
  ADD PRIMARY KEY (`nombre`);

--
-- Indices de la tabla `biografia`
--
ALTER TABLE `biografia`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `canciones`
--
ALTER TABLE `canciones`
  ADD PRIMARY KEY (`nombre`);

--
-- Indices de la tabla `componentes`
--
ALTER TABLE `componentes`
  ADD PRIMARY KEY (`nombre`);

--
-- Indices de la tabla `conciertos`
--
ALTER TABLE `conciertos`
  ADD PRIMARY KEY (`nombre`);

--
-- Indices de la tabla `discos`
--
ALTER TABLE `discos`
  ADD PRIMARY KEY (`nombre`);

--
-- Indices de la tabla `gestores`
--
ALTER TABLE `gestores`
  ADD PRIMARY KEY (`email`);

--
-- Indices de la tabla `pedidos`
--
ALTER TABLE `pedidos`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`email`);

--
-- Indices de la tabla `usuarios_p4`
--
ALTER TABLE `usuarios_p4`
  ADD PRIMARY KEY (`email`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `biografia`
--
ALTER TABLE `biografia`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT de la tabla `pedidos`
--
ALTER TABLE `pedidos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
